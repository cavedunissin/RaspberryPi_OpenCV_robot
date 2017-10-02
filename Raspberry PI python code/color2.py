import cv2.cv as cv
from time import sleep

capture = cv.CaptureFromCAM(0)
#cv.SetCaptureProperty(capture, 3, 160)
#cv.SetCaptureProperty(capture, 4, 120)#cv.CV_CAP_PROP_FRAME_HEIGHT,120) #will delay if you set high resolution

while True:
		img = cv.QueryFrame(capture)
		
		cv.Smooth(img, img, cv.CV_BLUR,3)
		hue_img = cv.CreateImage(cv.GetSize(img), 8, 3)
		cv.CvtColor(img, hue_img, cv.CV_BGR2HSV)

		threshold_img = cv.CreateImage(cv.GetSize(img),8 ,1)#red
		cv.InRangeS(hue_img, (150,100,70), (215,255,255), threshold_img)
			#(38,120,60)(75,255,255)#(90,103,130), (145,255,255)
			#150,100,50, 215,245,255
		threshold_img3 = cv.CreateImage(cv.GetSize(img),8 ,1)#blue
                cv.InRangeS(hue_img, (110,50,50), (130,255,255), threshold_img3)
                        #(38,120,60)(75,255,255)#(65,95,130), (125,190,255)

		storage = cv.CreateMemStorage(0)
		contour = cv.FindContours(threshold_img, storage, cv.CV_RETR_CCOMP, cv.CV_CHAIN_APPROX_SIMPLE)

		storage3 = cv.CreateMemStorage(0)
                contour3 = cv.FindContours(threshold_img3, storage3, cv.CV_RETR_CCOMP, cv.CV_CHAIN_APPROX_SIMPLE)	
		
		points = []
		while (contour or contour3):
			if contour:#red
				rect = cv.BoundingRect(list(contour))
				contour = contour.h_next()
				size  = (rect[2] * rect[3])
				mid = (rect[0]+rect[2])/2
				diag = (rect[2]**2 + rect[3]**2)**0.5
				if size > 500: #set trigger      
                               		pt1 = (rect[0], rect[1]) #left top
                                	pt2 = (rect[0]+rect[2], rect[1]+rect[3])  #right bottom
                                	cv.Rectangle(img, pt1, pt2, (0,0,255),3)  #draw rectangle 38,160,60
			else:#blue 
				rect3 = cv.BoundingRect(list(contour3))
                                contour3 = contour3.h_next()
                                size3 = (rect3[2] * rect3[3])
                                mid3 = (rect3[0]+rect3[2])/2
                                diag3 = (rect3[2]**2 + rect3[3]**2)**0.5
				if size3 > 250:
					pt13 = (rect3[0], rect3[1]) #left top
                                	pt23 = (rect3[0]+rect3[2], rect3[1]+rect3[3])  #right bottom
					cv.Rectangle(img, pt13, pt23, (255,0,0),3)	
				else:
                			sleep(0.01)

	        cv.ShowImage("Colour Tracking", img)
		#cv.ShowImage("Threshold", threshold_img2)
		#cv.ShowImage("Threshold2", threshold_img3)
#	else:	
		if cv.WaitKey(10) == 27:
			break

