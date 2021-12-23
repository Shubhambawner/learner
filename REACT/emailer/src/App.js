import logo from './logo.svg';
import './App.css';

function App() {
  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <p>
          Edit <code>src/App.js</code> and save to reload.
        </p>
        <a
          className="App-link"
          href="https://reactjs.org"
          target="_blank"
          rel="noopener noreferrer"
        >
          Learn React
        </a>
      </header>
    </div>
  );
}

const handleSubmit = (e) => {
  e.preventDefault(); // Prevents default refresh by the browser
  emailjs.sendForm(`gmail`, apiKey.TEMPLATE_ID, e.target, apiKey.USER_ID)
  .then((result) => {
  alert("Message Sent, We will get back to you shortly", result.text);
  },
  (error) => {
  alert("An error occurred, Please try again", error.text);
  });
  };

export default App; export {handleSubmit};
