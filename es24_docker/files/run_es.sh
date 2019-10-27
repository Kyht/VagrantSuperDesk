#!/bin/bash
ES_HOME=/usr/share/elasticsearch
LOG_DIR=/var/log/elasticsearch
DATA_DIR=/var/lib/elasticsearch
CONF_DIR=/etc/elasticsearch
# make sure we have the correct privileges
chown elasticsearch:elasticsearch $DATA_DIR
chown elasticsearch:elasticsearch $LOG_DIR

# run elasticsearch
setuser elasticsearch /usr/share/elasticsearch/bin/elasticsearch \
                                                -Des.default.path.home=${ES_HOME} \
                                                -Des.default.path.logs=${LOG_DIR} \
                                                -Des.default.path.data=${DATA_DIR} \
                                                -Des.default.path.conf=${CONF_DIR} 
