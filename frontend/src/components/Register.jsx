// Register.jsx
import React, { useState } from 'react';
import axios from 'axios';
import { numEncryption } from './CustomEncrypt';
import './Register.css';

const Register = () => {
  const [username, setUsername] = useState('');
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');

  const handleSubmit = async (e) => {
    e.preventDefault();

    // Encrypt username, email, and password
    const encryptedUsername = numEncryption(username);
    const encryptedEmail = numEncryption(email);
    const encryptedPassword = numEncryption(password);

    // Save encrypted values to respective files
    const fs = require('fs');
    const path = require('path');

    try {
      // Append the encrypted data to the respective files
      const dir = './'; // Assuming the files are in the same directory
      fs.appendFileSync(path.join(dir, 'Usernames.txt'), encryptedUsername + '\n');
      fs.appendFileSync(path.join(dir, 'Emails.txt'), encryptedEmail + '\n');
      fs.appendFileSync(path.join(dir, 'Passwords.txt'), encryptedPassword + '\n');

      // Register user (optional, if you still need to make an API call)
      await axios.post('http://localhost:5000/register', { username, email, password });
      
      alert('User registered successfully');
    } catch (error) {
      console.error('Error registering user:', error);
      alert('Error registering user');
    }
  };

  return (
    <div className="register-container">
      <h2>Register</h2>
      <form onSubmit={handleSubmit}>
        <input
          type="text"
          placeholder="Username"
          value={username}
          onChange={(e) => setUsername(e.target.value)}
        />
        <input
          type="email"
          placeholder="Email"
          value={email}
          onChange={(e) => setEmail(e.target.value)}
        />
        <input
          type="password"
          placeholder="Password"
          value={password}
          onChange={(e) => setPassword(e.target.value)}
        />
        <button type="submit">Register</button>
      </form>
    </div>
  );
};

export default Register;
