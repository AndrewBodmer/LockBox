import React from 'react';
import Header from './components/Header';
import Footer from './components/Footer';
import Login from './components/Login';
import Register from './components/Register';
import Body from './components/Body';
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
      <Footer />
    </div>
  );
}

export default App;
