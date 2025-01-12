import cv2
import numpy as np


color_map = {
    '#': (0, 0, 0),  # Black
    '.': (255, 255, 255),  # White
    '/': (255, 255, 255),
    'S': (0, 255, 0),  # Green
    'E': (0, 0, 255),  # Red
    'X': (255,0,0)
}


with open('inputTest', 'r') as file:
    lines = file.readlines()
height = len(lines)
width = max(len(line.strip()) for line in lines)
image = np.zeros((height, width, 3), dtype=np.uint8)


for y, line in enumerate(lines):
    for x, char in enumerate(line.strip()):
        if char in color_map:
            image[y, x] = color_map[char]
scale = 10
image_resized = cv2.resize(image, (width * scale, height * scale), interpolation=cv2.INTER_NEAREST)


cv2.imshow('Map', image_resized)
cv2.waitKey(0)
cv2.destroyAllWindows()
cv2.imwrite('map.png', image_resized)