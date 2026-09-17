/**
 * WHAT:
 *   Node HTTP server for the Raspberry Pi 5 brain.
 *
 * WHY:
 *   The Pi 5 backend is the source of truth for app commands, auth, and
 *   non-flight business logic. Expo and Next talk to this server, not to
 *   the flight MCU.
 *
 * HOW:
 *   Node's built-in http module listens on localhost. GET /health returns
 *   a small JSON status. No npm packages are used.
 *
 * IMPORTANT:
 *   This is a starter skeleton only. It is not authenticated yet and must
 *   not command motors. Keep it on localhost until real auth exists.
 *   Never trust phone or browser input as a reason to fly.
 */

const http = require("node:http");

const BRAIN_BACKEND_HOST = "127.0.0.1";
const BRAIN_BACKEND_PORT = 3000;

function sendJson(response, statusCode, body) {
  const jsonText = JSON.stringify(body);
  response.writeHead(statusCode, {
    "Content-Type": "application/json; charset=utf-8",
    "Content-Length": Buffer.byteLength(jsonText)
  });
  response.end(jsonText);
}

function handleBrainBackendRequest(request, response) {
  if (request.method === "GET" && request.url === "/health") {
    sendJson(response, 200, {
      ok: true,
      service: "brainBackendServer"
    });
    return;
  }

  sendJson(response, 404, {
    ok: false,
    error: "Not found"
  });
}

function startBrainBackendServer() {
  const server = http.createServer(handleBrainBackendRequest);

  server.listen(BRAIN_BACKEND_PORT, BRAIN_BACKEND_HOST, () => {
    console.log(
      `Brain backend listening on http://${BRAIN_BACKEND_HOST}:${BRAIN_BACKEND_PORT}`
    );
  });
}

startBrainBackendServer();
