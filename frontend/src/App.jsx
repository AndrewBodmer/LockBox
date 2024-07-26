import React from 'react';
import Header from './components/Header';
import Login from './components/Login';
import Register from './components/Register';
import './App.css';

function App() {
  return (
    <div className="App">
      <Header />
      <div className="content">
        <div className="auth-container">
          <Login />
          <Register />
        </div>
      </div>
    </div>
  );
}

export default App;
