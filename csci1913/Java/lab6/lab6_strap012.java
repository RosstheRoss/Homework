//package lab6;
//Above package used for debugging

class Rectangle extends Polygon {
    public Rectangle(int l, int w) {
        super(4, l, w, l, w);
    }
    public int area() {
        return this.side(0)*this.side(1);
    }
}

class Square extends Polygon {
    public Square(int l) {
        super(4, l, l, l, l);
    }
    public int area() {
        return this.side(0)*this.side(1);
    }
}