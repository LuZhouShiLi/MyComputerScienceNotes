FROM  openjdk:8-jre
MAINTAINER bytemecc


VOLUME /home/Lottery
RUN mkdir -p /home/Lottery
WORKDIR /home/Lottery
COPY ./jar/Lottery.jar /home/Lottery/app.jar

# ADD Lottery-API.jar /app.jar
RUN bash -c &#39;touch /home/Lottery/app.jar&#39;
ENTRYPOINT [&quot;java&quot;,&quot;-jar&quot;,&quot;/home/Lottery/app.jar&quot;]

