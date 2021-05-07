class Deque {
    constructor() {
      this.data = [];
      this.rear = 0;
    }
  
    push_front(element) {
      this.data.unshift(element);
      this.rear = this.rear + 1;
    }
  
    push_back(element) {
      this.data[this.rear] = element;
      this.rear = this.rear + 1;
    }
  
    pop_front() {
      if (this.isEmpty() === false) {
        this.rear = this.rear - 1;
        return this.data.shift();
      }
  
      return false;
    }
  
    pop_back() {
      if (this.isEmpty() === false) {
        this.rear = this.rear - 1;
        return this.data.pop();
      }
  
      return false;
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
  
      return false;
    }
  
    back() {
      if (this.isEmpty() === false) {
        return this.data[this.rear - 1];
      }
  
      return false;
    }
  }