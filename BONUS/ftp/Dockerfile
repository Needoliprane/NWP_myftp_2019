FROM ubuntu:bionic

RUN apt-get update && \
	apt-get install -y build-essential gcc

COPY ./app .

RUN make re

CMD [ "./myftp", "2007", "." ]
# CMD ["./myftp", "2007" "."]