import time

def water_sensor():
    #Placeholder for checking water level
    print("Checking water level...")

def main():
    #Initial time;
    start_time = time.time()

    while True:
        water_sensor()
        
        #Wait for 10 seconds
        time.sleep(10)

        #Calculate how long it took to check the water level
        end_time = time.time();
        elapsed_time = end_time - start_time

        #Output the elapsed time
        print("Time elapsed since last check: {} seconds".format(elapsed_time))

        #Update the start time for the next iteration
        start_time = time.time()

if __name__ == "__main__":
    main()