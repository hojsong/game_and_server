# pgadmin/config_local.py

import os

# 기본 PostgreSQL 서버 설정
DEFAULT_SERVERS = [
    {
        'name': 'postgresql',
        'host': 'postgresql',  # Docker Compose에서 설정한 서비스 이름
        'port': 5432,
        'username': 'root',
        'password': 'password',
        'ssl_mode': 'prefer',
    }
]
