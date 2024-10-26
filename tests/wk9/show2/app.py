# Searches for movies using Ajax with JSON

from cs50 import SQL
from flask import Flask, jsonify, render_template, request

app = Flask(__name__)

db = SQL("sqlite:///movies.db")

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/search")
def search():
    q = request.args.get("q")
    if q:
        movies = db.execute("SELECT title FROM movies WHERE title LIKE ? LIMIT 50", "%" + q + "%")
    else:
        movies = []
    return jsonify(movies)