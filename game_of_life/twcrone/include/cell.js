function Cell (alive) {
    this.alive = alive;
    this.color = this.alive ? "#0000bb" : "#ffffff";
    this.x = 0;
    this.y = 0;
    this.radius = 10;
    this.vx = 0;
    this.vy = 0;
    this.mass = 1;
    this.rotation = 0;
    this.scaleX = 1;
    this.scaleY = 1;
    this.color = utils.parseColor(this.color);
    this.lineWidth = 1;
    this.visible = true;
}

Cell.prototype.draw = function (context) {
    context.save();
    context.translate(this.x, this.y);
    context.rotate(this.rotation);
    context.scale(this.scaleX, this.scaleY);

    context.lineWidth = this.lineWidth;
    context.fillStyle = this.color;
    context.beginPath();
    //x, y, radius, start_angle, end_angle, anti-clockwise
    context.arc(0, 0, this.radius, 0, (Math.PI * 2), true);
    context.closePath();
    context.fill();
    if (this.lineWidth > 0) {
        context.stroke();
    }
    context.restore();
};

Cell.prototype.setAlive = function(alive) {
    this.alive = alive;
    this.color = this.alive ? "#0000bb" : "#ffffff";
};