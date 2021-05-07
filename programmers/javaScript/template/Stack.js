class Stack {
    constructor() {
        this.top = -1;
        this.bucket = [];
    }
    
    empty() {
        return this.bucket.length == 0;
    }

    push(element) {
        this.bucket[++this.top] = element;
    }

    pop() {
        if(this.top < 0) {
            return false;
        } else {
            let popVal = this.bucket[this.top];
            this.bucket = this.bucket.slice(0, this.top);
            this.top--;
            return true;
        }
    }

    top() {
        return this.bucket[this.bucket.length-1];
    }
    
    clear() {
        this.top = -1;
        this.bucket = [];
    }
}