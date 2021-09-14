void setup() {
    size(800,800);
}

void draw() {
    background(255);
    noFill();
    beginShape();
    float lineCount=1000;
    for (float i = 0; i<=lineCount; i++) {
        vertex(i,400+200*cos(i/80));
    }
    endShape();
}