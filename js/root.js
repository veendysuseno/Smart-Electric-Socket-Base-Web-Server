// root.js

// Function to handle the switch state
document.querySelectorAll(".onoffswitch-checkbox").forEach((checkbox) => {
  checkbox.addEventListener("change", function () {
    const switchNumber = this.id.replace("myonoffswitch", "");
    if (this.checked) {
      console.log(`Saklar ${switchNumber} dihidupkan`);
      // Tambahkan logika untuk menghidupkan saklar di backend
    } else {
      console.log(`Saklar ${switchNumber} dimatikan`);
      // Tambahkan logika untuk mematikan saklar di backend
    }
  });
});
