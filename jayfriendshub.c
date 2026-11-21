 <!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Mr. Jayant's Friendship Hub</title>

<style>
* {
    margin: 0;
    padding: 0;
    box-sizing: border-box;
    font-family: Arial, sans-serif;
}

body {
    background: #101322;
    color: white;
}

header {
    background: linear-gradient(120deg,#4527a0,#1565c0);
    padding: 25px;
    text-align: center;
}

header h1 {
    font-size: 27px;
}

header p {
    margin-top: 8px;
    color: #ddd;
}

nav {
    display: flex;
    justify-content: center;
    flex-wrap: wrap;
    background: #191e32;
}

nav button {
    background: transparent;
    border: none;
    color: white;
    padding: 15px;
    cursor: pointer;
    font-size: 15px;
}

nav button:hover {
    background: #4527a0;
}

.container {
    max-width: 950px;
    margin: auto;
    padding: 20px;
}

.card {
    background: #1d243b;
    padding: 20px;
    border-radius: 15px;
    margin: 15px 0;
    box-shadow: 0 4px 15px #0005;
}

h2 {
    color: #9fa8ff;
    margin-bottom: 15px;
}

input, textarea {
    width: 100%;
    padding: 12px;
    margin: 8px 0;
    border-radius: 8px;
    border: none;
}

.action {
    background: #7048e8;
    color: white;
    border: none;
    padding: 11px 18px;
    border-radius: 8px;
    cursor: pointer;
    margin: 5px;
}

.action:hover {
    background: #9475ff;
}

.page {
    display: none;
}

#home {
    display: block;
}

.game-grid {
    display: grid;
    grid-template-columns: repeat(auto-fit,minmax(130px,1fr));
    gap: 12px;
}

.game {
    padding: 25px 10px;
    text-align: center;
    background: #303858;
    border-radius: 12px;
    cursor: pointer;
}

.game:hover {
    background: #5144a0;
}

#board {
    display: grid;
    grid-template-columns: repeat(3,80px);
    gap: 5px;
    margin: 20px 0;
}

.cell {
    height: 80px;
    background: #303858;
    font-size: 30px;
    color: white;
    border: none;
    cursor: pointer;
}

#gallery img {
    width: 100px;
    height: 100px;
    object-fit: cover;
    border-radius: 10px;
    margin: 5px;
}

.message {
    background: #303858;
    padding: 12px;
    margin: 8px 0;
    border-radius: 8px;
    overflow-wrap: anywhere;
}

footer {
    text-align: center;
    padding: 25px;
    color: #aaa;
}
</style>
</head>

<body>

<header>
    <h1>👑 Mr. Jayant's Friendship Hub</h1>
    <p>Friends Forever • Memories Forever ❤️</p>
</header>

<nav>
    <button onclick="showPage('home')">🏠 Home</button>
    <button onclick="showPage('friends')">👥 Friends</button>
    <button onclick="showPage('games')">🎮 Games</button>
    <button onclick="showPage('gallery')">📸 Gallery</button>
    <button onclick="showPage('chat')">💬 Chat</button>
    <button onclick="showPage('admin')">👑 Admin</button>
</nav>

<div class="container">

<!-- HOME -->
<section id="home" class="page">
    <div class="card">
        <h2>Welcome to my website! ❤️</h2>
        <h3>Welcome, Friends!</h3>
        <p>Welcome to Mr. Jayant's Friendship Hub.</p>
        <br>
        <p>Play games, share memories and enjoy friendship!</p>
    </div>

    <div class="card">
        <h2>✨ Website Features</h2>
        <p>🎮 Play Games</p>
        <p>📸 Share Memories</p>
        <p>💬 Chat With Friends</p>
        <p>👑 Admin Controls</p>
    </div>
</section>

<!-- FRIENDS -->
<section id="friends" class="page">
    <div class="card">
        <h2>👥 Friends Zone</h2>
        <input id="friendName" placeholder="Enter your name">
        <button class="action" onclick="requestFriend()">Request Access</button>
        <div id="friendList"></div>
    </div>
</section>

<!-- GAMES -->
<section id="games" class="page">
    <div class="card">
        <h2>🎮 Games Zone</h2>
        <div class="game-grid">
            <div class="game" onclick="startTic()">⭕ Tic Tac Toe</div>
            <div class="game" onclick="guessGame()">🔢 Number Guess</div>
            <div class="game" onclick="rpsGame()">✊ Rock Paper Scissors</div>
            <div class="game" onclick="snakeGame()">🐍 Snake Game</div>
            <div class="game" onclick="alert('Multiplayer Ludo requires a server connection!')">🎲 Ludo</div>
        </div>
    </div>

    <div class="card">
        <h2>Tic Tac Toe</h2>
        <div id="board"></div>
        <p id="gameStatus">Player X's turn</p>
        <button class="action" onclick="resetTic()">Restart</button>
    </div>
</section>

<!-- GALLERY -->
<section id="gallery" class="page">
    <div class="card">
        <h2>📸 Memories Gallery</h2>
        <p>Photo uploads require admin approval.</p>
        <input type="file" id="photoInput" accept="image/*">
        <button class="action" onclick="uploadPhoto()">Upload Photo</button>
        <div id="gallery"></div>
    </div>
</section>

<!-- CHAT -->
<section id="chat" class="page">
    <div class="card">
        <h2>💬 Friends Chat</h2>
        <p>Demo chat. Messages are stored locally in this browser.</p>
        <div id="chatMessages"></div>
        <input id="chatName" placeholder="Your name">
        <input id="chatInput" placeholder="Write a message...">
        <button class="action" onclick="sendMessage()">Send</button>
    </div>
</section>

<!-- ADMIN -->
<section id="admin" class="page">
    <div class="card">
        <h2>👑 Admin Panel</h2>
        <p>Admin-only actions require secure authentication.</p>
        <input id="adminPass" type="password" placeholder="Admin password">
        <button class="action" onclick="adminLogin()">Admin Login</button>

        <div id="adminControls" style="display:none">
            <h3>Admin Dashboard</h3>
            <br>
            <button class="action" onclick="approveFriends()">Approve All Friend Requests</button>
            <button class="action" onclick="approvePhotos()">Approve All Photos</button>
            <button class="action" onclick="clearAllMessages()">Delete All Chats</button>
            <button class="action" onclick="clearFriends()">Clear Friend Requests</button>
            <button class="action" onclick="adminLogout()">Logout</button>
        </div>
    </div>
</section>

</div>

<footer>
    Made with ❤️ by Mr. Jayant
</footer>

<script>

// DEMO SETTINGS
// This is a local prototype, NOT secure authentication.
const DEMO_ADMIN_PASSWORD = "CHANGE_THIS_PASSWORD";

let requests = [];
let photos = [];
let messages = [];
let ticBoard = ["","","","","","","","",""];
let currentPlayer = "X";
let admin = false;

// NAVIGATION
function showPage(id) {
    document.querySelectorAll(".page").forEach(p => {
        p.style.display = "none";
    });
    document.getElementById(id).style.display = "block";
}

// FRIEND REQUEST
function requestFriend() {
    let name = document.getElementById("friendName").value.trim();

    if (!name) return alert("Enter your name");

    requests.push({name, approved:false});
    renderFriends();

    alert("Friend request submitted!");
}

function renderFriends() {
    let box = document.getElementById("friendList");
    box.innerHTML = "";

    requests.forEach((f,i) => {
        let div = document.createElement("p");
        div.textContent = f.name + " - " +
            (f.approved ? "Approved" : "Pending");
        box.appendChild(div);
    });
}

function approveFriends() {
    if (!admin) return;
    requests.forEach(f => f.approved = true);
    renderFriends();
}

// TIC TAC TOE
function renderTic() {
    let board = document.getElementById("board");
    board.innerHTML = "";

    ticBoard.forEach((value,i) => {
        let btn = document.createElement("button");
        btn.className = "cell";
        btn.textContent = value;
        btn.onclick = () => playTic(i);
        board.appendChild(btn);
    });
}

function playTic(i) {
    if (ticBoard[i] !== "") return;

    ticBoard[i] = currentPlayer;

    let win = [
        [0,1,2],[3,4,5],[6,7,8],
        [0,3,6],[1,4,7],[2,5,8],
        [0,4,8],[2,4,6]
    ];

    let winner = win.some(a =>
        ticBoard[a[0]] &&
        ticBoard[a[0]] === ticBoard[a[1]] &&
        ticBoard[a[1]] === ticBoard[a[2]]
    );

    renderTic();

    if (winner) {
        document.getElementById("gameStatus").textContent =
            currentPlayer + " wins!";
        return;
    }

    if (ticBoard.every(x => x !== "")) {
        document.getElementById("gameStatus").textContent = "Draw!";
        return;
    }

    currentPlayer = currentPlayer === "X" ? "O" : "X";
    document.getElementById("gameStatus").textContent =
        "Player " + currentPlayer + "'s turn";
}

function resetTic() {
    ticBoard = ["","","","","","","","",""];
    currentPlayer = "X";
    document.getElementById("gameStatus").textContent = "Player X's turn";
    renderTic();
}

// NUMBER GUESS
function guessGame() {
    let answer = Math.floor(Math.random()*10)+1;
    let guess = prompt("Guess a number between 1 and 10");

    if (guess === null) return;

    alert(Number(guess) === answer ?
        "Correct! 🎉" : "Wrong! Number was " + answer);
}

// ROCK PAPER SCISSORS
function rpsGame() {
    let options = ["Rock","Paper","Scissors"];
    let computer = options[Math.floor(Math.random()*3)];
    let user = prompt("Choose Rock, Paper or Scissors");

    if (!user) return;

    user = user.toLowerCase();
    let c = computer.toLowerCase();

    if (user === c) alert("Draw!");
    else if (
        (user==="rock" && c==="scissors") ||
        (user==="paper" && c==="rock") ||
        (user==="scissors" && c==="paper")
    ) alert("You win!");
    else alert("Computer chose " + computer + ". You lose!");
}

// SNAKE PLACEHOLDER
function snakeGame() {
    alert("Snake Game will be added in the next version.");
}

// GALLERY
function uploadPhoto() {
    let input = document.getElementById("photoInput");

    if (!input.files.length) return alert("Select a photo first.");

    if (input.files[0].size > 2*1024*1024) {
        return alert("Choose a photo smaller than 2 MB.");
    }

    let reader = new FileReader();

    reader.onload = function(e) {
        photos.push({src:e.target.result, approved:false});
        alert("Photo sent for admin approval!");
    };

    reader.readAsDataURL(input.files[0]);
}

function approvePhotos() {
    if (!admin) return;

    photos.forEach(p => p.approved = true);
    renderGallery();
}

function renderGallery() {
    let box = document.getElementById("gallery");
    box.innerHTML = "";

    photos.filter(p => p.approved).forEach(p => {
        let img = document.createElement("img");
        img.src = p.src;
        box.appendChild(img);
    });
}

// CHAT
function sendMessage() {
    let name = document.getElementById("chatName").value.trim();
    let msg = document.getElementById("chatInput").value.trim();

    if (!name || !msg) return alert("Enter name and message.");

    messages.push({
        name,
        msg,
        time:Date.now()
    });

    document.getElementById("chatInput").value = "";
    renderMessages();
}

function renderMessages() {
    let box = document.getElementById("chatMessages");
    box.innerHTML = "";

    messages = messages.filter(m =>
        Date.now() - m.time < 2*24*60*60*1000
    );

    messages.forEach(m => {
        let div = document.createElement("div");
        div.className = "message";
        div.textContent = m.name + ": " + m.msg;
        box.appendChild(div);
    });
}

// ADMIN
function adminLogin() {
    if (document.getElementById("adminPass").value === DEMO_ADMIN_PASSWORD) {
        admin = true;
        document.getElementById("adminControls").style.display = "block";
        alert("Welcome Admin!");
    } else {
        alert("Incorrect password!");
    }
}

function clearAllMessages() {
    if (!admin) return;

    if (confirm("Delete ALL messages?")) {
        messages = [];
        renderMessages();
        alert("All messages deleted from this demo.");
    }
}

function clearFriends() {
    if (!admin) return;
    requests = [];
    renderFriends();
}

function adminLogout() {
    admin = false;
    document.getElementById("adminControls").style.display = "none";
    document.getElementById("adminPass").value = "";
}

// INITIALIZE
renderTic();
renderMessages();
renderFriends();

</script>
</body>
</html>