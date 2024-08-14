// CustomDecrypt.jsx
export const numDecryption = (encryptedText) => {
    const encryptedArray = encryptedText.split(',').map(Number);
    const length = encryptedArray.length;
    let tempStr = new Array(length);
    const factors = [1, 2, 3, 4, 5]; // Same factors used in encryption
    let k = 0;
  
    // Reverse the application of factors from encrypted_text
    for (let j = 0; j < length; j++) {
      for (let i = 0; i < 256; i++) { // Try all possible values to reverse the multiplication
        if (i * factors[k] === encryptedArray[j]) {
          tempStr[j] = i;
          break;
        }
      }
      k = (k + 1) % 5; // Cycle through factors
    }
  
    // Reverse the second transformation (swap back adjacent elements)
    for (let j = 1; j < length; j += 2) {
      [tempStr[j], tempStr[j - 1]] = [tempStr[j - 1], tempStr[j]];
    }
  
    // Reverse the first transformation (reverse the array back)
    tempStr.reverse();
  
    // Reverse the encryption of the integer array
    let i = 5 + (length - 1); // Start from the last increment value
    for (let j = length - 1; j >= 0; j--) {
      tempStr[j] = tempStr[j] - i; // Use modular arithmetic to handle negative values
      i--;
    }
  
    // Convert integer array back to text
    let decryptedString = '';
    for (let j = 0; j < length; j++) {
      decryptedString += String.fromCharCode(tempStr[j]);
    }
  
    return decryptedString;
  };
  