// src/components/FileDownload.js
import React, { useState } from 'react';
import axios from 'axios';

const FileDownload = () => {
    const [filename, setFilename] = useState('');

    const handleDownload = async () => {
        try {
            const response = await axios.get(`http://127.0.0.1:5000/download/${filename}`, {
                responseType: 'blob'
            });
            const url = window.URL.createObjectURL(new Blob([response.data]));
            const link = document.createElement('a');
            link.href = url;
            link.setAttribute('download', filename);
            document.body.appendChild(link);
            link.click();
        } catch (error) {
            console.error('Error downloading file:', error);
        }
    };

    return (
        <div>
            <h2>Download File</h2>
            <input
                type="text"
                placeholder="Enter filename"
                value={filename}
                onChange={(e) => setFilename(e.target.value)}
            />
            <button onClick={handleDownload}>Download</button>
        </div>
    );
};

export default FileDownload;
