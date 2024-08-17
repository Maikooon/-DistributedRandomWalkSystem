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
                     .set_payload_claim("id", jwt::claim(std::to_string(6)))
                     .sign(jwt::algorithm::hs256{secret_key});
    // auto token = jwt::create()
    //                  .set_payload_claim("id", jwt::claim(std::to_string(RWer_id)))
    //                 .sign(jwt::algorithm::hs256{secret_key});
    // エンコードされたトークンを出力
    std::cout << "Generated JWT: " << token << std::endl;
    std::cout << "Token size: " << token.size() << std::endl;
    return token;
}

bool verifyJWT(const std::string &token, const std::string &secret_key, uint32_t &RWer_id)
{
    // 固定されたトークン文字列を使用する
    // const std::string fixed_token = "eyJhbGciOiJIUzI1NiJ9.eyJpZCI6IjYifQ.Wx11kP8GMJeUhnV4Th9t2tfCZyAIeidP1rcFiv_c_pY";

    // // 無理やりトークンのサイズを79バイトに合わせる
    // std::string adjusted_token = token.substr(0, 79);

    // トークンを受け取った時の状態を出力
    std::cout << "Received JWT: " << token << std::endl;
    std::cout << "Token size: " << token.size() << std::endl;

    try
    {
        auto decoded = jwt::decode(token);
        auto verifier = jwt::verify()
                            .allow_algorithm(jwt::algorithm::hs256{secret_key})
                            .with_claim("id", jwt::claim(std::to_string(6))); // 検証対象のRWer_idを指定

        verifier.verify(decoded);

        RWer_id = std::stoi(decoded.get_payload_claim("id").as_string());
        std::cout << "Extracted RWer_id: " << RWer_id << std::endl;
        return true;
    }
    catch (const std::exception &e) // 一般的な例外クラス
    {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return false;
    }
}
/*
検証時にでたエラーの種類は次の二つ
An error occurred: invalid token supplied
An error occurred: Invalid input: too much fill

ーどのような時なのか
ーどのような時に出るのか
ー原因は何か
ーどうすれば解消できるのか

*/