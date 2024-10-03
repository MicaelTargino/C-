# Use an official GCC image
FROM gcc:latest

# Install make
RUN apt-get update && apt-get install -y make

# Set the working directory in the container
WORKDIR /usr/src/app

# Copy the current directory contents into the container
COPY . .

# Create the necessary directories
RUN mkdir -p bin obj

# Run make to compile the project
RUN make

# Command to run the compiled application
CMD ["make", "run"]
