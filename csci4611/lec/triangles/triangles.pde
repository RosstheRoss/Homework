void draw() {
    fill(255);
    noStroke();
    beginShape(TRIANGLE_FAN);
    vertex(50,50);
    for (int x=0;x<=8;x++) {
        vertex(50+cos(x*PI/5)*30,50+sin(x*PI/5)*30);
    }
    endShape(CLOSE);
}