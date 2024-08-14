import React from 'react';
import './Body.css';

const Body = () => {
  return (
    <div className="body-container">
      <div className="search-bar-container">
        <input
          type="text"
          className="search-bar"
          placeholder="Search for files..."
        />
      </div>
      <div className="upload-section">
        <p>Click to Upload Files or Drag and Drop</p>
      </div>
      <div className="latest-files-section">
        <h2>Latest Uploaded Files</h2>
        <ul className="files-list">
          {/* Placeholder for latest files */}
          <li>No files uploaded yet.</li>
        </ul>
      </div>
    </div>
  );
};

export default Body;
