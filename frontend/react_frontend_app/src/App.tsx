import "./App.css";
import { useState } from "react";

function App() {
  const [getText, setText] = useState("");

  return (
    <>
      <input
        type="text"
        placeholder="Write somethings"
        value={getText}
        onChange={(e) => {
          setText(e.target.value);
        }}
      />
      <label>{getText}</label>
    </>
  );
}

export default App;
