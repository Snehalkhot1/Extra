// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract DocumentStorage {
    mapping(string => string) public documentHashes;

    function storeHash(string memory docName, string memory hash) public {
        documentHashes[docName] = hash;
    }

    function getHash(string memory docName) public view returns (string memory) {
        return documentHashes[docName];
    }
}
