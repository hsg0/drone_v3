"""
WHAT:
  Starter process for the on-device language model on the Pi 5.

WHY:
  The local LLM stays in its own folder so model code does not mix with
  the Node backend, the React apps, or the flight controller.

HOW:
  startLocalLlm() runs a tiny built-in HTTP server. GET /health says the
  process is up. GET /ask says no model is loaded yet. No model files and
  no LLM packages are downloaded.

IMPORTANT:
  This is a starter skeleton only. It does not load a model and must not
  invent answers that look like model output. It must never command motors
  or make flight decisions.
"""

import json
from http.server import BaseHTTPRequestHandler, HTTPServer

LOCAL_LLM_HOST = "127.0.0.1"
LOCAL_LLM_PORT = 8080


class LocalLlmRequestHandler(BaseHTTPRequestHandler):
    def sendJson(self, statusCode, body):
        jsonText = json.dumps(body).encode("utf-8")
        self.send_response(statusCode)
        self.send_header("Content-Type", "application/json; charset=utf-8")
        self.send_header("Content-Length", str(len(jsonText)))
        self.end_headers()
        self.wfile.write(jsonText)

    def do_GET(self):
        if self.path == "/health":
            self.sendJson(200, {
                "ok": True,
                "service": "localLlm",
                "modelLoaded": False
            })
            return

        if self.path == "/ask":
            self.sendJson(503, {
                "ok": False,
                "error": "No local model is loaded yet."
            })
            return

        self.sendJson(404, {
            "ok": False,
            "error": "Not found"
        })

    def log_message(self, format, *args):
        print("localLlm", args[0])


def startLocalLlm():
    localLlmServer = HTTPServer((LOCAL_LLM_HOST, LOCAL_LLM_PORT), LocalLlmRequestHandler)
    print(f"Local LLM starter listening on http://{LOCAL_LLM_HOST}:{LOCAL_LLM_PORT}")
    localLlmServer.serve_forever()


if __name__ == "__main__":
    startLocalLlm()
