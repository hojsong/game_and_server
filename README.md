# game_and_server

# Client

Dodge game

Easy Mode: 20 bullets and speed 1
Normal Mode: 25 bullets and speed 1-2
Hard Mode: 30 bullets and speed 1-3

Web Mode: Allows record upload and download.
Local Mode: Activated when 'Socket creation and connection fails' or 'Local mode is selected'

In Web Mode: Records are uploaded to both local storage and server.
In Local Mode: Records are saved only to local storage.


# Server Overview
This server is designed to operate on macOS, You need libpq to use postgresql(brew install libpq).
 utilizing Docker to run PostgreSQL and pgAdmin for seamless interaction. The server accepts a client's submitted name and the score at the end of the game, maintaining a leaderboard that stores and displays the top 10 scores. Both the leaderboard data and the scores are saved in a file and within SQL.

In version 1, the leaderboard is generated without using SQL; instead, scores are sorted in descending order based on the score and stored in both a file and a class.

In version 2, the server stores scores in SQL, retrieves the leaderboard values from the database, and also saves the scores in descending order to a file, which is then sent back to the client.

The communication between the client (located in client/Dodge) and the server (located in server/Server), as well as between the server and PostgreSQL (running in Docker), is established using TCP/IP(Socket).

Feel free to modify any part of this text as needed!