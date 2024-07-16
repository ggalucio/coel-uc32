#!/bin/bash

# Defina o diretório do projeto
project_dir="/c/ATProgetti"

# Mude para o diretório do projeto
cd "$project_dir"

# Verifique se a mudança de diretório foi bem-sucedida
if [ $? -ne 0 ]; then
    echo "Erro ao mudar para o diretório do projeto: $project_dir"
    exit 1
fi

# Obtenha a data e hora atuais
current_time=$(date +'%Y-%m-%d %H-%M-%S')

# Execute os comandos do Git
git pull origin $(git rev-parse --abbrev-ref HEAD) && \
git add -A && \
git commit -m "Project Updated at: $current_time" && \
git push origin $(git rev-parse --abbrev-ref HEAD)