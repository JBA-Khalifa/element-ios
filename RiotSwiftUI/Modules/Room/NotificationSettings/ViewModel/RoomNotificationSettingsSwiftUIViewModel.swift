// 
// Copyright 2021 New Vector Ltd
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

import Foundation
import Combine

@available(iOS 14.0, *)
class RoomNotificationSettingsSwiftUIViewModel: RoomNotificationSettingsViewModel, ObservableObject {

    @Published var viewState: RoomNotificationSettingsViewState
    
    lazy var cancellables = Set<AnyCancellable>()
    
    override init(roomNotificationService: RoomNotificationSettingsServiceType, initialState: RoomNotificationSettingsViewState) {
        self.viewState = initialState
        super.init(roomNotificationService: roomNotificationService, initialState: initialState)
    }
    
    override func update(viewState: RoomNotificationSettingsViewState) {
        super.update(viewState: viewState)
        self.viewState = viewState
    }
}
