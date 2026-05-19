import requests
from fastapi import FastAPI

app = FastAPI()


@app.get("/")
def home():
    print("HOME HERE")
    return {"message": "Olááááá home"}


@app.get("/get-api")
def get_api():
    print("GET API HERE")
    return {"message": "Get Functional"}


@app.post("/post-api")
def post_api(data: dict):
    print("POST HERE")
    return {"status": "post successful", "data": data, "message": "Post inserted"}


if __name__ == "__main__":
    home()
    get_api()
    data = {"name": "Diogo"}

    response = requests.post("http://localhost:3000/post-api", json=data)
    post_api(data)

    print(response.status_code)
    print(response.text)
