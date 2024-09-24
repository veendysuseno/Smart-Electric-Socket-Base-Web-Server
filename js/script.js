// Inisialisasi counter untuk error pada username dan password
let usernameErrorCount = 0;
let passwordErrorCount = 0;

// Validasi form saat submit
document
  .getElementById("loginForm")
  .addEventListener("submit", function (event) {
    var username = document.getElementById("username").value;
    var password = document.getElementById("password").value;

    let errorMessage = "";

    // Cek apakah username kosong
    if (username === "") {
      event.preventDefault(); // Mencegah pengiriman form jika username kosong
      usernameErrorCount++; // Tambah counter error untuk username
      errorMessage += `Username wajib diisi! (Gagal ${usernameErrorCount} kali)\n`;
    }

    // Cek apakah password kosong
    if (password === "") {
      event.preventDefault(); // Mencegah pengiriman form jika password kosong
      passwordErrorCount++; // Tambah counter error untuk password
      errorMessage += `Password wajib diisi! (Gagal ${passwordErrorCount} kali)\n`;
    }

    // Tampilkan pesan jika ada error
    if (errorMessage !== "") {
      alert(errorMessage);
    }
  });

// Ambil parameter dari URL untuk cek error login
const urlParams = new URLSearchParams(window.location.search);

// Cek apakah parameter 'error' ada di dalam URL (misalnya jika login gagal)
if (urlParams.has("error")) {
  // Ambil elemen HTML untuk menampilkan pesan error
  const messageElement = document.getElementById("message");

  // Tampilkan pesan error login
  messageElement.innerHTML =
    "<span style='color:red;'>Username atau password salah!</span>";
}
