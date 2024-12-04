//
//  MyCustomViewManager.swift
//  aws_ivs_demo
//
//  Created by dev on 12/4/24.
//

@objc (RCTMyCustomViewManager)
class MyCustomViewManager: RCTViewManager {

  override static func requiresMainQueueSetup() -> Bool {
    return true
  }

  override func view() -> UIView! {
    return MyCustomView()
  }

}
