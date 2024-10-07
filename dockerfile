
FROM gcc:latest

WORKDIR /usr/src/app

COPY . .

RUN g++ -o myapp main.cpp

CMD ["./myapp"]



## add other components