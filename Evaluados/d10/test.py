import cv2
import numpy as np

# Read input as matrix of integers
with open('input', 'r') as f:
    lines = f.readlines()
    matrix = []
    for line in lines:
        row = [int (char) for char in line.strip()]
        matrix.append(row)
    data = np.array(matrix, dtype=np.uint8)

# Scale values (0=255 white, 9=0 black) 
img = 255 - (data * 28)  

# Resize for better visibility
scale = 10
img_resized = cv2.resize(img, (data.shape[1]*scale, data.shape[0]*scale), 
                        interpolation=cv2.INTER_NEAREST)

# Display and save
cv2.imshow('Height Map', img_resized)
cv2.waitKey(0)
cv2.destroyAllWindows()
cv2.imwrite('height_map.png', img_resized)