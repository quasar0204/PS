class Queue {
    constructor() {
      this.data = [];
      this.rear = 0;
    }
  
    push(element) {
        this.data[this.rear] = element;
        this.rear = this.rear + 1;
    }
  
    pop() {
      if (this.isEmpty() === false) {
        this.rear = this.rear - 1;
        return this.data.shift();
      }
    }
  
    size() {
      return this.rear;
    }
  
    empty() {
      return this.rear === 0;
    }
  
    front() {
      if (this.isEmpty() === false) {
        return this.data[0];
      }
    }
  }
  