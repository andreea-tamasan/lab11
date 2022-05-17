cmake_minimum_required(VERSION 3.21)
project(laab9)

set(CMAKE_CXX_STANDARD 14)

add_executable(laab9 main.cpp Product/Product.cpp Product/Product.h Repo/Repo.cpp Repo/Repo.h tests/Tests.cpp tests/Tests.h Service/Service.cpp Service/Service.h UI/UI.cpp UI/UI.h Money/Money.cpp Money/Money.h Repo/RepoFile.cpp Repo/RepoFile.h Repo/IRepo.h Tonomat/Tonomat.cpp Tonomat/Tonomat.h Service/MoneyService.cpp Service/MoneyService.h Repo/RepoMoney.h Exception/Exception.h)
