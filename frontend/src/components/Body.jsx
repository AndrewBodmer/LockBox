import React from 'react';
import Login from './Login';
import Register from './Register';

const Body = () => {
  return (
    <div className="container">
      <div className="left-half">
        <Login />
      </div>
      <div className="right-half">
        <Register />
      </div>
    </div>
  );
};

export default Body;