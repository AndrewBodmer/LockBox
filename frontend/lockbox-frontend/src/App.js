import React, { useEffect, useState } from 'react';
import axios from 'axios';
import Login from './components/Login';
import Register from './components/Register';
import FileUpload from './components/FileUpload';
import FileDownload from './components/FileDownload';

function App() {
  const [message, setMessage] = useState('');
  const [token, setToken] = useState(null);

  useEffect(() => {
    axios.get('http://127.0.0.1:5000/api/hello')
      .then(response => {
        setMessage(response.data.message);
      })
      .catch(error => {
        console.error('There was an error fetching the data!', error);
      });
  }, []);

  const handleLogin = (token) => {
    setToken(token);
  };

  const handleLogout = () => {
    setToken(null);
  };

  return (
    <div className="App">
      <h1>{message}</h1>
      {!token ? (
        <div>
          <Login onLogin={handleLogin} />
          <Register onRegister={handleLogin} />
        </div>
      ) : (
        <div>
          <button onClick={handleLogout}>Logout</button>
          <FileUpload />
          <FileDownload />
        </div>
      )}
    </div>
  );
}

export default App;
