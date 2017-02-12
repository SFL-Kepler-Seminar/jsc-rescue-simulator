#pragma once

class LineSegment {
public:
    QRectF rect;
    bool isInside(QPointF point) {
        return rect.contains(point);
    }
};

class Playground {
public:
    std::vector<LineSegment> line_segemnts;
};
