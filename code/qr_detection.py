# =========================================================
# RC CAR WIRELESS QR CODE DETECTION
# =========================================================
#
# Phone 1:
#     IP Webcam mounted on RC car
#
#          ↓ Wi-Fi
#
# TP-Link Archer AX55 Router
#
#          ↓ Wi-Fi
#
# Computer:
#     Receives video stream
#     Detects QR code using OpenCV
#
# =========================================================

import cv2


# =========================================================
# CAMERA SOURCE
# =========================================================

# ---------------------------------------------------------
# For testing with the computer's webcam:
# ---------------------------------------------------------

CAMERA_SOURCE = 0


# ---------------------------------------------------------
# For Phone 1 IP Webcam:
#
# Replace the example IP address with the actual
# IP address displayed by the IP Webcam application.
#
# Example:
#
# CAMERA_SOURCE = "http://192.168.0.105:8080/video"
#
# ---------------------------------------------------------


# =========================================================
# QR CODE DETECTOR
# =========================================================

qr_detector = cv2.QRCodeDetector()


# =========================================================
# OPEN CAMERA / VIDEO STREAM
# =========================================================

cap = cv2.VideoCapture(CAMERA_SOURCE)

if not cap.isOpened():
    print("ERROR: Unable to open camera or IP Webcam stream.")
    print("Check the camera source and network connection.")
    exit()


print("Camera stream started.")
print("QR detection started.")
print("Press 'q' to quit.")


# =========================================================
# MAIN LOOP
# =========================================================

while True:

    # -----------------------------------------------------
    # Read video frame
    # -----------------------------------------------------

    ret, frame = cap.read()

    if not ret:
        print("ERROR: Unable to receive video frame.")
        break


    # -----------------------------------------------------
    # Detect and decode QR code
    # -----------------------------------------------------

    data, points, _ = qr_detector.detectAndDecode(frame)


    # -----------------------------------------------------
    # If QR code is detected
    # -----------------------------------------------------

    if points is not None and data:

        print("QR Code Detected:")
        print(data)


        # -------------------------------------------------
        # Convert QR points to integer coordinates
        # -------------------------------------------------

        points = points.astype(int)


        # -------------------------------------------------
        # Draw QR bounding box
        # -------------------------------------------------

        for i in range(len(points[0])):

            start = tuple(points[0][i])
            end = tuple(
                points[0][(i + 1) % len(points[0])]
            )

            cv2.line(
                frame,
                start,
                end,
                (0, 255, 0),
                2
            )


        # -------------------------------------------------
        # Display QR data on video
        # -------------------------------------------------

        cv2.putText(
            frame,
            data,
            (20, 40),
            cv2.FONT_HERSHEY_SIMPLEX,
            0.8,
            (0, 255, 0),
            2
        )


    # =====================================================
    # DISPLAY VIDEO
    # =====================================================

    cv2.imshow(
        "RC Car - Wireless QR Detection",
        frame
    )


    # =====================================================
    # QUIT
    # =====================================================

    if cv2.waitKey(1) & 0xFF == ord("q"):
        break


# =========================================================
# CLEANUP
# =========================================================

cap.release()
cv2.destroyAllWindows()

print("QR detection stopped.")
