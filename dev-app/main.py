from fastapi import FastAPI
from fastapi.responses import FileResponse
from pydantic import BaseModel
from fastapi.middleware.cors import CORSMiddleware

app = FastAPI()

# Enable CORS
app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

# Store the latest GPS data
latest_gps = {"latitude": None, "longitude": None}

# Pydantic model for incoming GPS data
class GPSData(BaseModel):
    latitude: float
    longitude: float

# Endpoint to receive GPS data
@app.post("/gps")
async def receive_gps(data: GPSData):
    global latest_gps
    latest_gps = {"latitude": data.latitude, "longitude": data.longitude}
    return {"message": "GPS data received"}

# Endpoint to get the latest GPS data
@app.get("/gps/latest")
async def get_latest_gps():
    return latest_gps

# Serve the homepage
@app.get("/")
async def serve_homepage():
    return FileResponse("index.html")
