function Square(props) {
  return (
    <button className="square" onClick={props.onClick}>
      {props.value}
    </button>
  );
}

class Board extends React.Component {
  renderSquare(i) {
    return (
      <Square
        value={this.props.squares[i]}
        onClick={() => this.props.onClick(i)}
      />
    );
  }

  render() {
    return (
      <div>
        <div className="status">{this.props.value}</div>
        <div className="board-row">
          {this.renderSquare(0)}
          {this.renderSquare(1)}
          {this.renderSquare(2)}
        </div>
        <div className="board-row">
          {this.renderSquare(3)}
          {this.renderSquare(4)}
          {this.renderSquare(5)}
        </div>
        <div className="board-row">
          {this.renderSquare(6)}
          {this.renderSquare(7)}
          {this.renderSquare(8)}
        </div>
      </div>
    );
  }
}

class Game extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      H: [{ squares: Array(10).fill(null) }],
      current: 0
    };
  }

  #xo = "X";
  #status = "Next player: X";
  #winner = false;
  #rep = "";

  handleClick(i) {
    const squares = this.state.H[this.state.current].squares.slice();
    if (squares[i] === null && !this.#winner) {
      squares[i] = this.#xo;
      squares[9] = this.state.H[this.state.current].squares[9] + 1;
      let H2 = this.state.H;
      H2.push({ squares: squares });
      this.setState({ H: H2, current: this.state.current + 1 });
      this.#winner = Wi(squares);
      //console.log("the winner is : ", this.#winner, squares);
       
      if (this.#xo == "X") {
        this.#xo = "O";
      } else {
        this.#xo = "X";
      }this.#status = "Next player: " + this.#xo;
      if (this.#winner == "X" || this.#winner == "O") {
        this.#status = "Winner is : " + this.#winner;
      }
      //console.log(H2);
    } else {
      //console.log(i);
    }
  }

  Reset() {
    this.setState({ H: [{ squares: Array(10).fill(null) }], current: 0 });
    this.#xo = "X";
    this.#status = "Next player: X";
    this.#rep = "";
    this.#winner = false
  }

  jumpTo(i) {
    //console.log(i,i%2)

    const squares = this.state.H[i].squares.slice();
    if (!Equal(this.state.H[this.state.current].squares, squares)) {
      this.#rep += "re. ";
      if (i % 2 != 0) {
        this.#xo = "O";
        this.#status = "Next player: O";
      } else {
        this.#xo = "X";
        this.#status = "Next player: X";
      }
      console.log(this.state.H[this.state.current].squares == squares);
      this.#winner = Wi(squares);
      let H2 = this.state.H;
      H2.push({ squares: squares });
      this.setState({ H: H2, current: this.state.current + 1 });
    } else {
      console.log(this.state.H[this.state.current].squares, squares);
      alert("already on current move !");
    }
  }

  render() {
    const reset = "reset";
    const arr = this.state.H.map((j, i) => {
      let desc = "go to move: " + j.squares[9];
      if (i == this.state.H.length - 1 && j.squares[9] != null) {
        desc = "current move: " + j.squares[9];
        return (
          <li key={i}>
            <button>{desc}</button>
          </li>
        );
      }
      if (j.squares[9] == null) {
        return (
          <li key={"12345423"}>
            <button onClick={() => this.Reset()}>{reset}</button>
          </li>
        );
      }

      return (
        <li key={i}>
          <button onClick={() => this.jumpTo(i)}>{desc}</button>
        </li>
        
      );
    });
    return (
      <div className="game">
        <div className="game-board">
          <Board
            squares={this.state.H[this.state.current].squares}
            onClick={(i) => this.handleClick(i)}
            value={ this.#status}
          />
        </div>

        <div className="game-info">
          <div>{/* status */}</div>
          <ol>{arr}</ol>
        </div>
      </div>
    );
  }
}

function Wi(arr) {
  let j = null;
  const brr = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [1, 4, 8],
    [6, 4, 2]
  ];
  flag = false;
  brr.forEach((e) => {
    if (arr[e[0]] != null && arr[e[0]] == arr[e[1]] && arr[e[1]] == arr[e[2]]) {
      j = arr[e[0]];
      //return arr[e[0]] dosnt work!! why?
    }
  });
  return j;
}

function Equal(object1, object2) {
  const keys1 = Object.keys(object1);
  const keys2 = Object.keys(object2);
  if (keys1.length !== keys2.length) {
    return false;
  }
  for (let key of keys1) {
    if (object1[key] !== object2[key]) {
      return false;
    }
  }
  return true;
}

// ========================================

ReactDOM.render(<Game />, document.getElementById("root"));
