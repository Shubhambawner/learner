import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';



class Square extends React.Component {
    constructor(){
      super()
      this.state = {
        value:null
      }
    }

    render() {
      return (
        <button className="square"
        onClick={
            ()=>{
                this.setState({value:this.props.value})                    
            }
        }
        >
          { this.state.value}
        </button>
      );
    }
  }
  
  class Board extends React.Component {
    constructor(){
      super()
      this.state = {
        value : 'X'
      }
    }
    renderSquare(i) {
      return <Square value = {i}/>;
    }
  
    render() {
      const status = 'Next player: X';
  
      return (
        <div 
        onClick={
          ()=>{
            if(this.state.value==="X"){
              this.setState({value:'O'})
            }else if(this.state.value==="O"){
              this.setState({value:'X'})
            }
          }
        }>
          <div className="status">{status}</div>
          <div className="board-row">
            {this.renderSquare(this.state.value)}
            {this.renderSquare(this.state.value)}
            {this.renderSquare(this.state.value)}
          </div>
          <div className="board-row">
            {this.renderSquare(this.state.value)}
            {this.renderSquare(this.state.value)}
            {this.renderSquare(this.state.value)}
          </div>
          <div className="board-row">
            {this.renderSquare(this.state.value)}
            {this.renderSquare(this.state.value)}
            {this.renderSquare(this.state.value)}
          </div>
        </div>
      );
    }
  }
  
  class Game extends React.Component {
    render() {
      return (
        <div className="game">
          <div className="game-board">
            <Board />
          </div>
          <div className="game-info">
            <div>{/* status */}</div>
            <ol>{/* TODO */}</ol>
          </div>
        </div>
      );
    }
  }
  
  // ========================================
  
  ReactDOM.render(
    <Game />,
    document.getElementById('root')
  );
  