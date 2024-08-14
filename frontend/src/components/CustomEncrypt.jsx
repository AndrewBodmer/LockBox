// CustomEncrypt.jsx
export const numEncryption = (text) => {
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
  
    // Convert encrypted array to a string for storage
    return encryptedArray.join(',');
  };
  