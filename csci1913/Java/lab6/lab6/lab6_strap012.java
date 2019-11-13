package lab6;

class Rectangle extends Polygon {
    public Rectangle(int l, int w) {
        super(4, l, w, l, w);
    }
    public int area() {
        return this.side(0)*this.side(1);
    }
}

class Square extends Rectangle {
    public Square(int l) {
        super( l, l);
    }
    // public int area() {
    //     return this.side(0)*this.side(1);
    // }
}