import cv2
import urllib.request
import numpy as np
import cvlib as cv
from cvlib.object_detection import draw_bbox
import concurrent.futures

url = 'http://192.168.246.174/cam-lo.jpg'

def run1():
    cv2.namedWindow("live transmission", cv2.WINDOW_AUTOSIZE)
    while True:
        img_resp = urllib.request.urlopen(url)
        imgnp = np.array(bytearray(img_resp.read()), dtype=np.uint8)
        im = cv2.imdecode(imgnp, -1)
 
        cv2.imshow('live transmission', im)
        key = cv2.waitKey(5)
        if key == ord('q'):
            break
            
    cv2.destroyAllWindows()
        
def run2():
    cv2.namedWindow("detection", cv2.WINDOW_AUTOSIZE)
    while True:
        img_resp = urllib.request.urlopen(url)
        imgnp = np.array(bytearray(img_resp.read()), dtype=np.uint8)
        im = cv2.imdecode(imgnp, -1)

        if im is not None:
            # Detect common objects
            bbox, label, conf = cv.detect_common_objects(im)
            # Draw bounding box over detected objects
            im = draw_bbox(im, bbox, label, conf)
 
            cv2.imshow('detection', im)
        else:
            print("Failed to retrieve image or detection failed")
            
        key = cv2.waitKey(5)
        if key == ord('q'):
            break
            
    cv2.destroyAllWindows()

if __name__ == '__main__':
    print("Starting tests...")
    
    # Test object detection independently first
    print("Testing object detection independently")
    run2()  # Run object detection to ensure it works
    
    # If object detection works, try running live transmission and detection sequentially
    print("Testing sequential execution")
    run1()  # First run live transmission
    run2()  # Then run object detection
    
    # If both work, consider running them in parallel using threading
    print("Testing parallel execution with ThreadPoolExecutor")
    with concurrent.futures.ThreadPoolExecutor() as executor:
        f1 = execut
