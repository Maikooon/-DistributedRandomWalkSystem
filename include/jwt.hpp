#include <exception>
#include <string>
#include <stdexcept>
#include <iostream>
#include "jwt-cpp/jwt.h"
#include <openssl/hmac.h>
#include <openssl/sha.h>

std::string generateJWT(uint32_t RWer_id, const std::string &secret_key)
{
    auto token = jwt::create()
                     .set_payload_claim("id", jwt::claim(std::to_string(RWer_id)))
                     .sign(jwt::algorithm::hs256{secret_key});
    return token;
}

bool verifyJWT(const std::string &token, const std::string &secret_key, uint32_t &RWer_id)
{
    // とりあえず実行されたら文字列を表示する
    std::cout << "aaaaaaaaaaa" << std::endl;
    try
    {
        auto decoded = jwt::decode(token);
        auto verifier = jwt::verify()
                            .allow_algorithm(jwt::algorithm::hs256{secret_key})
                            .with_claim("id", jwt::claim(std::string{}));

        verifier.verify(decoded);
        std::cout << "Extracted RWer_id: " << RWer_id << std::endl;
        RWer_id = std::stoi(decoded.get_payload_claim("id").as_string());
        return true;
    }
    catch (const std::exception &e) // 一般的な例外クラス
    {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return false;
    }
}
