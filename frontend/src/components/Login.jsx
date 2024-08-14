// Login.jsx
import React, { useState } from 'react';
import { numEncryption } from './CustomEncrypt';
import './Login.css';

const fs = require('fs');
const path = require('path');

const Login = () => {
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');

  const handleSubmit = (e) => {
    e.preventDefault();

    // Encrypt the email and password
    const encryptedEmail = numEncryption(email);
    const encryptedPassword = numEncryption(password);

    // File paths for Usernames.txt, Emails.txt, and Passwords.txt
    const dir = './'; // Assuming the files are in the same directory
    const emailsPath = path.join(dir, 'Emails.txt');
    const passwordsPath = path.join(dir, 'Passwords.txt');

    try {
      // Read the contents of the Emails.txt and Passwords.txt files
      const emails = fs.readFileSync(emailsPath, 'utf-8').split('\n').filter(Boolean);
      const passwords = fs.readFileSync(passwordsPath, 'utf-8').split('\n').filter(Boolean);

      // Check if the encrypted email exists and if the corresponding password matches
      const emailIndex = emails.indexOf(encryptedEmail);
      if (emailIndex !== -1 && passwords[emailIndex] === encryptedPassword) {
        alert('Login successful');
        // You can also handle token storage or redirection here
      } else {
        alert('Invalid credentials');
      }
    } catch (error) {
      console.error('Error reading files:', error);
      alert('An error occurred during login');
    }
  };

  return (
    <div className="login-container">
      <h2>Login</h2>
      <form onSubmit={handleSubmit}>
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
        <button type="submit">Login</button>
      </form>
    </div>
  );
};

export default Login;
