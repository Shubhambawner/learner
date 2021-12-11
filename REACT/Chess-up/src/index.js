
import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';

class Square extends React.Component {
  //console.log(props.value)
  #x = this.props.value[1];
  #y = this.props.value[2];
  #color = (this.#x + this.#y) % 2 == 0 ? "whiteSquare" : "blackSquare";
  

  render() {
    return (
      <button
        id={"t" + this.#x + "" + this.#y}
        className={this.#color}
        onClick={() => this.props.onClick()}
      ><img className= "fit" src={mapURL(this.props.value[0])} />
        {this.props.value[0]}
      </button>
    );
  }
}

class Board extends React.Component {
  renderSquare(i, j) {
    //console.log(i,j,this.props.squares[i][j])
    return (
      <Square
        key={i * 10 + j}
        value={[this.props.squares[i][j], i, j]}
        onClick={() => this.props.onClick(i, j)}
      />
    );
  }

  render() {
    //console.log("hello", this.props.squares);
    const arr = this.props.squares;
    const brr = arr.map((i, j) => {
      if (j != 8) {
        const crr = i.map((i1, j1) => {
          return this.renderSquare(j, j1);
        });
        return (
          <div key={j} className="board-row">
            {crr}
          </div>
        );
      }
    });

    return <div id="sadsad">{brr}</div>;
  }
}

class Game extends React.Component {
  constructor(props) {
    super(props);
    let a0 = [null, null, null, null, null, null, null, null];
    let a1 = [null, null, null, null, null, null, null, null];
    let a2 = [null, null, null, null, null, null, null, null];
    let a3 = [null, null, null, null, null, null, null, null];
    let a4 = [null, null, null, null, null, null, null, null];
    let a5 = [null, null, null, null, null, null, null, null];
    let a6 = [null, null, null, null, null, null, null, null];
    let a7 = [null, null, null, null, null, null, null, null];
    let hrr = [a0, a1, a2, a3, a4, a5, a6, a7];
    //console.log('hrr',hrr)
    hrr.push({ turn: "0", stateNumber: 0, underCheck: null });
    //creating the multi dimentional array,
    //this:
    // hrr = Array(8).fill(Array(8).fill((null)));
    //wont work, as fill just asigns references, so array of nulls is actually created only once.
    //console.log('hrr',hrr)
    let erra = chessStart(hrr);
    this.state = {
      H: [{ squares: erra }],
      current: 0
    };
  }

  #xo = "X";
  #status = "Next player: X";
  #winner = false;
  #rep = "";
  #piece = null;
  #range = [];

  handleClick(i, j) {
    let squares = superSlice(this.state.H[this.state.current].squares);
    if (
      squares[i][j] &&
      !this.#winner &&
      squares[i][j][0] === squares[8].turn &&
      this.#range.indexOf(i + "" + j) == -1
    ) {
      //console.log('rrr')
      unmark(this.#range);
      this.#piece = null;
      this.#range = [];

      this.#piece = i + "" + j;
      this.#range = getRange(i, j, squares[i][j][1], squares); //return array of co-ordinates that are under attack by piece at i,j
      mark(this.#range, squares); // marks green/red all squares under attack, get element by id, and update class list
    } else if (
      //squares[i][j][0] === squares[8].turn &&
      this.#piece != null &&
      this.#range.length != 0 &&
      this.#range.indexOf(i + "" + j) != -1
    ) {
      //console.log(i);
      let vrr = this.state.H;

      squares = movePieceTo(i, j, squares, this.#piece[0], this.#piece[1]); // update array squares to bring piece from this.#piece to i,j, also killing any piece if there on i,j
      squares[8].stateNumber++;
      let oponentKing = squares[8].turn == 0 ? "1K" : "0K";
      let king = squares[8].turn == 0 ? "0K" : "1K";

      if (isUnderCheck(king, i, j, squares)) {
        alert("the piece is pin! ");
      } else {
        if (squares[8].turn != "0") squares[8].turn = "0";
        else squares[8].turn = "1";

        squares[8].underCheck = isUnderCheck(oponentKing, i, j, squares);

        vrr.push({ squares: squares });
        this.setState({ H: vrr, current: this.state.current + 1 });

        unmark(this.#range);
        this.#piece = null;
        this.#range = [];
      }
    }
  }

  Reset() {
    let a0 = [null, null, null, null, null, null, null, null];
    let a1 = [null, null, null, null, null, null, null, null];
    let a2 = [null, null, null, null, null, null, null, null];
    let a3 = [null, null, null, null, null, null, null, null];
    let a4 = [null, null, null, null, null, null, null, null];
    let a5 = [null, null, null, null, null, null, null, null];
    let a6 = [null, null, null, null, null, null, null, null];
    let a7 = [null, null, null, null, null, null, null, null];
    let hrr = [a0, a1, a2, a3, a4, a5, a6, a7];
    hrr.push({ turn: "0", stateNumber: 0, underCheck: null });
    this.setState({
      H: [{ squares: chessStart(hrr) }],
      current: 0
    });

    this.#xo = "X";
    this.#status = "Next player: X";
    this.#rep = "";
    this.#winner = false;
    this.#piece = null;
    this.range = [];
  }

  jumpTo(i) {
    //console.log(i,i%2)

    const squares = superSlice(this.state.H[i].squares);
    if (!deepEqual(this.state.H[this.state.current].squares, squares)) {
      this.#rep += "re. ";
      if (i % 2 != 0) {
        this.#xo = "O";
        this.#status = "Next player: O";
      } else {
        this.#xo = "X";
        this.#status = "Next player: X";
      }
      //console.log(this.state.H[this.state.current].squares == squares);
      this.#winner = Wi(squares);
      let H2 = superSlice(this.state.H);
      H2.push({ squares: squares });
      this.setState({ H: H2, current: this.state.current + 1 });
    } else {
      console.log(this.state.H[this.state.current].squares, squares);
      alert("already on current move !");
    }
  }

  render() {
    //console.log(this.state.H[0].squares, "hre");
    let brr = superSlice(this.state.H);
    const arr = brr.map((j, i) => {
      let desc = "go to move: " + j.squares[8].stateNumber;
      //console.log(j,i, "hreyyyyyy");
      if (i == brr.length - 1 && j.squares[8].stateNumber != 0) {
        desc = "current move: " + j.squares[8].stateNumber;
        return (
          <li key={i}>
            <button>{desc}</button>
          </li>
        );
      }
      if (j.squares[8].stateNumber == 0) {
        desc = "reset";
        return (
          <li key={i}>
            <button onClick={() => this.Reset()}>{desc}</button>
          </li>
        );
      }

      return (
        <li key={i}>
          <button onClick={() => this.jumpTo(i)}>{desc}</button>
        </li>
      );
    });

    let t = brr[this.state.current].squares[8].turn == 0 ? "whites" : "Blacks";

    return (
      <div className="game">
        <div className="game-board">
          <h3>{"turn of: " + t}</h3>
          <Board
            squares={brr[this.state.current].squares}
            onClick={(i, j) => this.handleClick(i, j)}
            value={this.#status}
          />
        </div>

        <div className="game-info">
          <div>{/* status */}</div>
          <ol>{arr}</ol>
        </div>
        <img src="https://images.chesscomfiles.com/chess-themes/pieces/neo/150/bk.png" alt="pic" />
      </div>
    );
  }
}

function deepEqual(object1, object2) {
  const keys1 = Object.keys(object1);
  const keys2 = Object.keys(object2);
  if (keys1.length !== keys2.length) {
    return false;
  }
  for (const key of keys1) {
    const val1 = object1[key];
    const val2 = object2[key];
    const areObjects = isObject(val1) && isObject(val2);
    if (
      areObjects && !deepEqual(val1, val2) ||
      !areObjects && val1 !== val2
    ) {
      return false;
    }
  }
  return true;
}
function isObject(object) {
  return object != null && typeof object === 'object';
}

function Wi() {
  return false;
}

/////////////////////////////////////////////////////////////////////
//game specific functions
///////////////////////////////////////////////////////////////////////
function mark(trr, squares) {
  
  for (var j of trr) {
    console.log(j, 'mark')
    if (!squares[j[0]][j[1]])
      document.querySelector("#t" + j).classList.add("blue-mark");
    else {
      document.querySelector("#t" + j).classList.add("red-mark");
    }
  }
}

function unmark(trr) {
  for (var j of trr) {
    console.log(j, 'unmark')
    document.querySelector("#t" + j).classList.remove("green-mark");
    document.querySelector("#t" + j).classList.remove("blue-mark");
    document.querySelector("#t" + j).classList.remove("red-mark");
  }
}

function movePieceTo(i, j, tsquares, ib, jb) {
  let squares = superSlice(tsquares);
  squares[i][j] = squares[ib][jb];
  squares[ib][jb] = null;
  return squares;
}

//TODO
function isUnderCheck(king, i, j, squares) {
  for (let m of squares) {
    for (let n of squares) {
      //if (getRange(i, j, squares[m][n], squares).indexOf(king) != -1)
      //  return true;
      console.log(m,n)
    }
  }
  return false;
  //TODO
}


function getRange(i, j, p, squares) {
  //console.log(p)
  let arr = [];
  if (p == "p") {
    //console.log(p)
    arr = pawnRange(i, j, squares);
  } else if (p == "r") {
    arr = rookhRange(i, j, squares);
  } else if (p == "b") {
    arr = bishopRange(i, j, squares);
  } else if (p == "q") {
    arr = rookhRange(i, j, squares).concat(bishopRange(i, j, squares));
  } else if (p == "k") {
    arr = knightRange(i, j, squares);
  } else if (p == "K") {
    arr = kingRange(i, j, squares);
  }
  let brr = [];
  if (squares[8].underCheck != null) {
    for (let i of arr) {
    }
  }

  return arr;
}

function pawnRange(i, j, squares) {
  //if(isPin(i, j, squares)) return [];
  let arr = [];
  if (squares[i][j][0] == 0) {
    if (i + 1 <= 7 && squares[i + 1][j] == null) arr.push(i + 1 + "" + j);
    if (i == 1) {
      if (squares[i + 2][j] == null) arr.push(i + 2 + "" + j);
    }
    if (squares[i + 1] && squares[i + 1][j + 1]) arr.push(i + 1 + "" + (j + 1));
    if (squares[i + 1] && squares[i + 1][j - 1]) arr.push(i + 1 + "" + (j - 1));
    //console.log(arr,'pawnb')
    return arr;
  } else {
    //black pawn
    if (i - 1 >= 0 && squares[i - 1][j] == null) arr = [i - 1 + "" + j];
    if (i == 6) {
      if (i - 1 >= 0 && squares[i - 1][j] == null) arr.push(i - 2 + "" + j);
    }
    if (squares[i - 1] && squares[i - 1][j + 1]) arr.push(i - 1 + "" + (j + 1));
    if (squares[i - 1] && squares[i - 1][j - 1]) arr.push(i - 1 + "" + (j - 1));
    //console.log(arr,'pawn')
    return arr;
  }
}
function rookhRange(i, j, squares) {
  //if(isPin(i, j, squares)) return [];
  let arr = Vr(i, j, squares);
  return arr;
}
function bishopRange(i, j, squares) {
  //if(isPin(i, j, squares)) return [];
  let arr = Cr(i, j, squares);
  return arr;
}
function knightRange(i, j, squares) {
  //if(isPin(i, j, squares)) return [];
  //console.log(typeof i, typeof j);
  let arr = [];
  if (
    squares[i + 1] &&
    squares[i + 1][j + 2] !== undefined &&
    (squares[i + 1][j + 2] === null ||
      squares[i + 1][j + 2][0] != squares[i][j][0])
  )
    arr.push(i + 1 + "" + (j + 2));
  if (
    squares[i - 1] &&
    squares[i - 1][j + 2] !== undefined &&
    (squares[i - 1][j + 2] === null ||
      squares[i - 1][j + 2][0] != squares[i][j][0])
  )
    arr.push(i - 1 + "" + (j + 2));
  if (
    squares[i + 1] &&
    squares[i + 1][j - 2] !== undefined &&
    (squares[i + 1][j - 2] === null ||
      squares[i + 1][j - 2][0] != squares[i][j][0])
  )
    arr.push(i + 1 + "" + (j - 2));
  if (
    squares[i - 1] &&
    squares[i - 1][j - 2] !== undefined &&
    (squares[i - 1][j - 2] === null ||
      squares[i - 1][j - 2][0] != squares[i][j][0])
  )
    arr.push(i - 1 + "" + (j - 2));
  if (
    squares[i + 2] &&
    squares[i + 2][j + 1] !== undefined &&
    (squares[i + 2][j + 1] === null ||
      squares[i + 2][j + 1][0] != squares[i][j][0])
  )
    arr.push(i + 2 + "" + (j + 1));
  if (
    squares[i + 2] &&
    squares[i + 2][j - 1] !== undefined &&
    (squares[i + 2][j - 1] === null ||
      squares[i + 2][j - 1][0] != squares[i][j][0])
  )
    arr.push(i + 2 + "" + (j - 1));
  if (
    squares[i - 2] &&
    squares[i - 2][j + 1] !== undefined &&
    (squares[i - 2][j + 1] === null ||
      squares[i - 2][j + 1][0] != squares[i][j][0])
  )
    arr.push(i - 2 + "" + (j + 1));
  if (
    squares[i - 2] &&
    squares[i - 2][j - 1] !== undefined &&
    (squares[i - 2][j - 1] === null ||
      squares[i - 2][j - 1][0] != squares[i][j][0])
  )
    arr.push(i - 2 + "" + (j - 1));
  console.log(arr);
  return arr;
}
function kingRange(i, j, squares) {
  let arr = [];
  for (let c = -1; c < 2; c++) {
    for (let cc = -1; cc < 2; cc++) {
      if (
        squares[i + c] &&
        squares[i + c][j + cc] !== undefined &&
        (squares[i + c][j + cc] === null ||
          squares[i + c][j + cc][0] != squares[i][j][0])
      )
        arr.push(i + c + "" + (j + cc));
    }
  }
  return arr;
}

function chessStart(arr) {
  //console.log("Pnullbyte: ",arr);

  arr[1] = ["0p", "0p", "0p", "0p", "0p", "0p", "0p", "0p"];
  arr[6] = ["1p", "1p", "1p", "1p", "1p", "1p", "1p", "1p"];
  arr[0][0] = "0r";
  arr[0][7] = "0r";
  arr[7][0] = "1r";
  arr[7][7] = "1r";
  arr[0][1] = "0k";
  arr[0][6] = "0k";
  arr[7][1] = "1k";
  arr[7][6] = "1k";
  arr[0][2] = "0b";
  arr[0][5] = "0b";
  arr[7][2] = "1b";
  arr[7][5] = "1b";
  arr[0][3] = "0K";
  arr[0][4] = "0q";
  arr[7][3] = "1K";
  arr[7][4] = "1q";

  //console.log("nullbyte: ",arr)
  return arr;
}

function Cr(i, j, squares) {
  let arr = []
  
  for(let c = i-1, cc = j-1 ; c*cc>=0 ; c--,cc--){
    if(squares[c][cc]!=null){
      if(squares[c][cc][0]!=squares[i][j][0])
        arr.push(c+""+cc)
      break;
    }
    arr.push(c+""+cc)
  }
  for(let c= i+1, cc = j+1; (c<=7 && cc<=7) ; c++,cc++){
    if(squares[c][cc]!=null){
      if(squares[c][cc][0]!=squares[i][j][0])
        arr.push(c+""+cc)
      break;
    }
    arr.push(c+""+cc)
  }
  for(let cc = j-1,c=i+1 ; cc>=0 && c<=7 ; cc--,c++){
    if(squares[c][cc]!=null){
      if(squares[c][cc][0]!=squares[i][j][0])
        arr.push(c+""+cc)
      break;
    }
    arr.push(c+""+cc)
  }
  for(let cc= j+1, c = i-1; cc<=7 && c>=0 ; cc++,c--){
    if(squares[c][cc]!=null){
      if(squares[c][cc][0]!=squares[i][j][0])
        arr.push(c+""+cc)
      break;
    }
    arr.push(c+""+cc)
  }
  
  
  return arr 
}
function Vr(i, j, squares) {
  let arr = []
  
  for(let c = i-1; c>=0 ; c--){
    if(squares[c][j]!=null){
      if(squares[c][j][0]!=squares[i][j][0])
        arr.push(c+""+j)
      break;
    }
    arr.push(c+""+j)
  }
  for(let c= i+1; c<=7 ; c++){
    if(squares[c][j]!=null){
      if(squares[c][j][0]!=squares[i][j][0])
        arr.push(c+""+j)
      break;
    }
    arr.push(c+""+j)
  }
  for(let c = j-1; c>=0 ; c--){
    if(squares[i][c]!=null){
      if(squares[i][c][0]!=squares[i][j][0])
        arr.push(i+""+c)
      break;
    }
    arr.push(i+""+c)
  }
  for(let c= j+1; c<=7 ; c++){
    if(squares[i][c]!=null){
      if(squares[i][c][0]!=squares[i][j][0])
        arr.push(i+""+c)
      break;
    }
    arr.push(i+""+c)
  }
  
  
  return arr 
}

function superSlice(arr) {
  //this is only for 2d, to make recursive one
  const brr = JSON.parse(JSON.stringify(arr));
  return brr;
}

function mapURL(str){
switch(str){
    case "0p":return "https://images.chesscomfiles.com/chess-themes/pieces/neo/150/wp.png";break;
    case "1p":return "https://images.chesscomfiles.com/chess-themes/pieces/neo/150/bp.png";break;
    case "0K":return "https://images.chesscomfiles.com/chess-themes/pieces/neo/150/wk.png";break;
    case "0q":return "https://images.chesscomfiles.com/chess-themes/pieces/neo/150/wq.png";break;
    case "0b":return "https://images.chesscomfiles.com/chess-themes/pieces/neo/150/wb.png";break;
    case "0k":return "https://images.chesscomfiles.com/chess-themes/pieces/neo/150/wn.png";break;
    case "0r":return "https://images.chesscomfiles.com/chess-themes/pieces/neo/150/wr.png";break;
    case "1K":return "https://images.chesscomfiles.com/chess-themes/pieces/neo/150/bk.png";break;
    case "1q":return "https://images.chesscomfiles.com/chess-themes/pieces/neo/150/bq.png";break;
    case "1b":return "https://images.chesscomfiles.com/chess-themes/pieces/neo/150/bb.png";break;
    case "1k":return "https://images.chesscomfiles.com/chess-themes/pieces/neo/150/bn.png";break;
    case "1r":return "https://images.chesscomfiles.com/chess-themes/pieces/neo/150/br.png";break;
    default : return null;
}
}

// ========================================

ReactDOM.render(<Game />, document.getElementById("root"));


//export default App
