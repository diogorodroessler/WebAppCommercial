use axum::{
    Json,
    routing::{get, post},
};
use serde::{Deserialize, Serialize};

#[derive(Serialize)]
struct Message {
    name: String,
}

#[derive(Deserialize)]
struct InputData {
    name: String,
}

async fn hello() -> Json<Message> {
    Json(Message {
        name: "Hello, From Rust API".to_string(),
    })
}

async fn post_data(Json(payload): Json<InputData>) -> Json<Message> {
    Json(Message {
        name: format!("Hello post_data {}", payload.name),
    })
}

#[tokio::main]
async fn main() {
    let app = axum::Router::new()
        .route("/", get(hello))
        .route("/post-api", post(post_data));

    let listener = tokio::net::TcpListener::bind("0.0.0.0:3000").await.unwrap();

    println!("Server running on 3000");

    axum::serve(listener, app).await.unwrap();
}
