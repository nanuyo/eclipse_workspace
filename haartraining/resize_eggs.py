import os
import cv2

pic_num = 1
    
if not os.path.exists('pos'):
       os.makedirs('pos')
        

img = cv2.imread("pos/"+egg+str(pic_num)+".jpg")
resized_image = cv2.resize(img, (50, 50))
            cv2.imwrite("neg/"+str(pic_num)+".jpg",resized_image)
            pic_num += 1
            
        except Exception as e:
            print(str(e))  
