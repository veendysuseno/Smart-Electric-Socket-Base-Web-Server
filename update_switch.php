<?php
$servername = "localhost";
$username = "admin"; // Default username for XAMPP
$password = "admin"; // Default password is empty
$dbname = "smart_electric_socket"; // Your database name

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Get switch number and status from the URL
$switch_number = intval($_GET['switch']);
$status = $_GET['status'];

// Prepare and bind
$stmt = $conn->prepare("INSERT INTO switch_status (switch_number, status) VALUES (?, ?)");
$stmt->bind_param("is", $switch_number, $status);

// Execute the statement
if ($stmt->execute()) {
    echo "Record updated successfully";
} else {
    echo "Error: " . $stmt->error;
}

// Close connections
$stmt->close();
$conn->close();