import React, { useState } from 'react';

const EncryptionComponent = () => {
  const [inputText, setInputText] = useState('');
  const [encryptedText, setEncryptedText] = useState([]);
  const [decryptedText, setDecryptedText] = useState('');

  const numEncryption = (text) => {
    const length = text.length;
    let tempStr = new Array(length);
    const factors = [1, 2, 3, 4, 5]; // Avoid zero to prevent multiplication by zero

    // Convert text to integer array
    for (let j = 0; j < length; j++) {
      tempStr[j] = text.charCodeAt(j);
    }

    // Encrypt the integer array
    let i = 5;
    for (let j = 0; j < length; j++) {
      tempStr[j] = tempStr[j] + i;
      i++;
    }

    // Perform first transformation (reverse the array)
    tempStr.reverse();

    // Perform second transformation (swap adjacent elements)
    for (let j = 1; j < length; j += 2) {
      [tempStr[j], tempStr[j - 1]] = [tempStr[j - 1], tempStr[j]];
    }

    // Apply factors to the encrypted integer array
    let encryptedArray = [];
    let k = 0;
    for (let j = 0; j < length; j++) {
      encryptedArray[j] = tempStr[j] * factors[k];
      k = (k + 1) % 5; // Cycle through factors
    }

    setEncryptedText(encryptedArray);
  };

  const numDecryption = (encryptedArray) => {
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

    setDecryptedText(decryptedString);
  };

  const handleEncrypt = () => {
    numEncryption(inputText);
  };

  const handleDecrypt = () => {
    numDecryption(encryptedText);
  };

  return (
    <div>
      <h1>Encryption & Decryption</h1>
      <textarea
        value={inputText}
        onChange={(e) => setInputText(e.target.value)}
        placeholder="Enter text to encrypt"
      />
      <button onClick={handleEncrypt}>Encrypt</button>
      <h2>Encrypted Text:</h2>
      <p>{encryptedText.join(', ')}</p>
      <button onClick={handleDecrypt}>Decrypt</button>
      <h2>Decrypted Text:</h2>
      <p>{decryptedText}</p>
    </div>
  );
};

export default EncryptionComponent;
