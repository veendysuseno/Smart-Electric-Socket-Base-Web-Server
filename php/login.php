<?php
// Mulai session
session_start();

// Simulasi cek login (gantilah ini dengan logika sebenarnya)
$username = $_POST['USERNAME'];
$password = $_POST['PASSWORD'];

// Contoh sederhana, ganti dengan validasi ke database atau sistem autentikasi lainnya
if ($username === 'admin' && $password === 'admin') {
    // Jika berhasil login, arahkan ke halaman root.html
    header('Location: ../root.html');
    exit;
} else {
    // Jika gagal, kembalikan ke index.html dengan parameter error
    header('Location: ../index.html?error=1');
    exit;
}